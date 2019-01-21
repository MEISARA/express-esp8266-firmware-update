import cors from 'cors'
import bodyParser from 'body-parser'
import express from 'express'
import config from './configs/config'
import router from './services/router'

const app = express()

const port = config.port

app.use(cors())
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())

app.use('/', router)

app.listen(port)
console.log(`RESTful API on port ${port}`)
