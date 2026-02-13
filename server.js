import express from 'express'
import path from 'path'
import { ErisConsole } from './src/utils/eris_console.js'

const APP = express()
const PORT = 8080

APP.use(express.static("examples/"))
APP.use(express.static("src/"))
APP.use(express.static("libs/"))

APP.listen(PORT, () => {
	ErisConsole.log("[Example Server Started!]")
	ErisConsole.log(`http://localhost:${PORT}/`)
})
