console.log("Vessio Backup Script Initialized");

const fs = require('fs');
fs.writeFileSync('./NodeJs_notes/Custom_nodejs_project/vessio_backup.txt', 'This is a backup file created by Vessivo backup script.');

console.log("Backup file 'vessio_backup.txt' created successfully.");