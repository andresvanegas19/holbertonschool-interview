#!/usr/bin/python3
""" Count it! """
import requests

URL_TEMPLATE = 'https://www.reddit.com/r/{}/hot.json?after={}'


def finding(subreddit, word_list, most_s_titles, next_s_redd=""):
    """
    Query reddit for hot posts and print total occurrences of each keyword in
    a recursive way

    Args:
        subreddit(string): string representing subreddit to search for
        word_list(array): keywords to search in the subreddit
        most_s_titles: dictionary of number of occurrences of elements
        in word_list that are found in the request
        next_s_redd: pagination feature of the reddit api

    Return:
        most_s_titles or None
    """

    # Making the request
    res = requests.get(
        # the url
        "https://www.reddit.com/r/{}/hot.json?after={}".format(subreddit, next_s_redd),
        headers={'User-agent': 'product'},
        allow_redirects=False
    )

    if res.status_code != 200:
        return None
    if next_s_redd is None:
        return most_s_titles

    for i in res.json().get('data').get('children'):
        title_s = i.get('data').get('title').split()
        for word in set(word_list):
            if word.lower() in [x.lower() for x in title_s]:
                if most_s_titles.get(word):
                    most_s_titles[word] += 1
                else:
                    most_s_titles[word] = 1

    next_s_redd = res.json().get('data').get('after')
    finding(subreddit, word_list, most_s_titles, next_s_redd)
    return most_s_titles



def count_words(subreddit, word_list):
    """
    Query reddit for hot posts and print total occurrences of each keyword in
    a recursive way

    NOTE:
        You may change the prototype, but it must be able to be called with
        just a subreddit supplied and a list of keywords. AKA you can add a
        counter or anything else, but the function must work without supplying
        a starting value in the main.

    Args:
        subreddit(string): string representing subreddit to search for
        word_list(array): Array of keywords to search in the subreddit

    Return:
        each keyword with its corresponding count in order
    """
    most_s_title = finding(subreddit, word_list, {})

    if most_s_title:
        f_sorted = sorted(
            # sort by value
            most_s_title.items(),
            # lambda function to sort by key
            key=lambda val: val[1],
            # reverse order
            reverse=True
        )
        for k, v in f_sorted:
            if v != 0:
                print('{}: {}'.format(k, v))
