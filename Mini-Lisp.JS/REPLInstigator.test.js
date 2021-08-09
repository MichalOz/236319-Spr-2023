const REPLInstigator = require('./REPLInstigator')
const fs = require('fs')
const streams = require('memory-streams')
const testsFolderPath = './repl_tests'

const testFile = async name => {
	const inputPath = `${testsFolderPath}/${name}.in`
	const expectedPath = `${testsFolderPath}/${name}.e`

	if (!fs.existsSync(inputPath) || !fs.existsSync(expectedPath)) {
		return false
	}	

	const outputStream = new streams.WritableStream()
	
	const ri = new REPLInstigator(
		fs.createReadStream(inputPath),
		outputStream,
		null
	)
		
	await new Promise(resolve => setTimeout(resolve, 100))

	const expectedPromise = new Promise((resolve) => {
		const expectedStream = fs.createReadStream(expectedPath)
		let chunks = []
	    expectedStream.on('data', (chunk) => chunks.push(Buffer.from(chunk)))
	    expectedStream.on('end', () => resolve(Buffer.concat(chunks).toString('utf8')))
  	})

  	expect(expectedPromise).resolves.toStrictEqual(outputStream.toString())
  	return true
}

test('repl', async () => {
	for (var i = 1;; i++) {
		if (!(await testFile('t' + i))) {
			break
		}
	}
})