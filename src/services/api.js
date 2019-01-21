import downloadFirmware from '../resolvers/downloadFirmware'

export default {
	downloadFirmware: (req, res) => (downloadFirmware(req, res))
}
