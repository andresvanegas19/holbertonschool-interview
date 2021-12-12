#!/usr/bin/python3
""" Count it! """
import requests

REDDIT_URL = 'https://reddit.com/r/{}/hot.json'


def count_words(subreddit, word_list, mfsr=None, init_key_val={}, res_dic={}):
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
    pagination = ''
    if mfsr:
        pagination += '?after=' + mfsr

    response = requests.get(
        REDDIT_URL.format(subreddit) + pagination,
        headers={"User-Agent": "client"}
    )

    if response.status_code != 200:
        return

    if init_key_val == {}:
        # Initialize the dictionary
        keys = [word.lower() for word in word_list]
        # Initialize the dictionary with 0
        for key in keys:
            init_key_val[key] = 0
            res_dic[key] = keys.count(key)

    response_dict = response.json()
    # Get the data from the response
    data = response_dict['data']
    mfsr = data['after']
    posts = data['children']

    for post in posts:
        # Get the title of the post
        data_in_post = post['data']
        title = data_in_post['title']
        words_in_title = title.split()
        # Check if the word is in the title
        for word in words_in_title:
            for key in init_key_val:
                if word.lower() == key.lower():
                    init_key_val[key] += 1

    if mfsr:
        # Call the function again
        count_words(subreddit, word_list, mfsr, init_key_val, res_dic)
    else:
        for key, val in res_dic.items():
            if val > 1:
                init_key_val[key] *= val

        s_resp = sorted(
            sorted(init_key_val.items(), key=lambda x: x[0]),
            key=lambda x: (-x[1], x[0])
        )

        for res in s_resp:
            if res[1] > 0:
                print('{}: {}'.format(res[0], res[1]))
