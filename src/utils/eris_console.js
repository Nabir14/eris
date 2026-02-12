export class ErisConsole {
	static log(log_string) {
		console.log(`(ERIS_LOG): ${log_string}`)
	}
	
	static warn(warn_string) {
		 console.warn(`(ERIS_WARN): ${warn_string}`)
	}
	
	static error(err_string) {
		console.error(`(ERIS_ERROR): ${err_string}`)
	}
}
