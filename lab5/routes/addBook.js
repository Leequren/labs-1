const {writeFile} = require('node:fs')

const addBookOptsGet = {
    handler: (req, reply) => {
        reply.view('/templates/main.ejs')
    }
}
const addBookOptsPost = {
    handler: async (req, reply) => {
        const body = req.body
        if (body.authorName && body.bookName && body.genreName && String(body.referenceGenre) && String(body.popular)) {
            let stringData = ``
            stringData += `${body.authorName}|${body.bookName}|${body.genreName}|${body.referenceGenre}|${body.popular}\n`
            console.log(stringData)
            await writeFile('books.txt', stringData, {flag: 'a+', encoding: 'utf-8'}, (err) => {
                if (err) {
                    console.log(err)
                }
            })
            reply.code(200)
        }
    }
}

module.exports = function (fastify, opts, next) {
    fastify.get('/', addBookOptsGet)
    fastify.post('/', addBookOptsPost)
    next()
}