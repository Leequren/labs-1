const {readFileSync} = require('node:fs')

const listBookGet = {
    handler: (req, reply) => {
        let data = readFileSync('books.txt', {encoding: 'utf-8'}).split('\n')
        data = data.slice(0, data.length - 1)
        let booksArray = []
        for (let i of data) {
            booksArray.push(i.split('|'))
        }
        console.log(booksArray)
        reply.view('/templates/list.ejs', {books: booksArray})
    }
}

module.exports = function (fastify, opts, next) {
    fastify.get('/list', listBookGet)
    next()
}