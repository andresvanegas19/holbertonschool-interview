#!/usr/bin/node

const request = require("request");
const link = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

/**
 * @description Function that returns the number of characters in a film
 * @param {string} link
 * @returns {number}
 */
request(link, async function (error, resp, body) {
  if (error) console.log(error);

  const characters = await JSON.parse(body).characters;
  for (const character of characters) {
    const rep = await new Promise((resolve, reject) => {
      request(character, function (err, rp, bd) {
        if (err) reject(err);

        resolve(JSON.parse(bd).name);
      });
    });

    console.log(rep);
  }
});
