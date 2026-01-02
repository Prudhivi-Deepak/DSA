const fs = require('fs');
const path = require('path');
const rootDir = require('../util/path');
const p = path.join(rootDir, 'data', 'users.json');
// const Users = [];

const getUsersFromFile = (callback) => {
    fs.readFile(p, (err, fileContent) => { //read existing file content
        console.log("file content :: ", fileContent);
        let users = [];
        if (err) {// file exists - parse the content
            // return [];
            callback([]);
        }
        else {
            // return JSON.parse(fileContent);
            callback(JSON.parse(fileContent));
        }
    });
}

module.exports = class User {

    constructor(name, imageUrl, description, price) {
        this.title = name;
        this.imageUrl = imageUrl;
        this.description = description;
        this.price = price;
    }

    save() {
        // Users.push(this);
        // fs.readFile(p, (err, fileContent) => { //read existing file content
        //     console.log("file content :: ", fileContent);
        //     let users = [];
        //     if (!err) {// file exists - parse the content
        //         users = JSON.parse(fileContent);
        //     }
        //     users.push(this); //push current user object
        //     //write user to the json file 
        //     fs.writeFile(p, JSON.stringify(users), (err) => {
        //         console.log(err);
        //     });
        // })

        getUsersFromFile((users) => {
            users.push(this); //push current user object
            //write user to the json file 
            fs.writeFile(p, JSON.stringify(users), (err) => {
                console.log(err);
            });
        });
    }

    static fetchAll(callback) {
        // const p = path.join(rootDir, 'data', 'users.json');
        // this is a call back function - async
        // it registers the callback and move to next line - return nothing for this function
        // many ways to solve this 
        // 1 way is to accept callback function as parameter
        // fs.readFile(p, (err, fileContent) => { //read existing file content
        //     console.log("file content :: ", fileContent);
        //     let users = [];
        //     if (err) {// file exists - parse the content
        //         // return [];
        //         callback([]);
        //     }
        //     else {
        //         // return JSON.parse(fileContent);
        //         callback(JSON.parse(fileContent));
        //     }
        // });
        // return Users;

        getUsersFromFile(callback);
    }


}