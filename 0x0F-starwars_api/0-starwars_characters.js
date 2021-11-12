#!/usr/bin/node

const request = require('request');
const baseURL = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

(async function () {
  request(baseURL, async function (error, response, body) {
    if (error) {
      console.log(error);
      return;
    }

    const characters = JSON.parse(body).characters;

    for (const character of characters) {
      await new Promise(function (resolve, reject) {
        request(character, function (err, res, bod) {
          if (err) {
            console.log(err);
            reject(err);
          } else {
            console.log(JSON.parse(bod).name);
            resolve();
          }
        });
      });
    }
  });
})();
