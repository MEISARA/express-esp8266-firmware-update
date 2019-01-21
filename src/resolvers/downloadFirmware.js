import path from 'path'

const downloadFirmware = (req, res) => {
	const file = req.params.file
  const fileLocation = path.join(`${__dirname}../../../firmware/`, file)
  console.log(fileLocation)
  res.download(fileLocation, file)
}

export default downloadFirmware
