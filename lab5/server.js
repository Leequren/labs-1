const path = require('node:path')
const PORT = 1070
const fastify = require('fastify')({logger: true})

fastify.register(require('@fastify/autoload'), {
    dir: path.join(__dirname, 'routes')
})

fastify.register(require('@fastify/static'), {
    root: path.join(__dirname, 'static'),
    prefix: '/static'
})

fastify.register(require('@fastify/view'), {
    engine: {
        ejs: require('ejs')
    }
})

fastify.listen(PORT)
    .then((err) => {
        console.log(err)
    })