const Sequelize = require('sequelize');

// below code creates a new Sequelize instance to connect to a MySQL database (connection pool)
const sequelize = new Sequelize(
    'node_project',
    'root',
    'root',
    {
        dialect: 'mysql',
        host: 'localhost'
    }
);

module.exports = sequelize;

