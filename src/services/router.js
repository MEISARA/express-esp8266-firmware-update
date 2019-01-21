import express from 'express'
import api from './api'

const router = express.Router()

router.route('/').post((req, res) => {
  res.end()
  console.log("Do not allow connection.")
})

router.route('/download/:file(*)').get((req, res) => {
  api.downloadFirmware(req, res)
})

export default router