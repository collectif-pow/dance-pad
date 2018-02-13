const player = require('play-sound')({ player: 'afplay' });
const SerialPort = require('serialport');
const parsers = SerialPort.parsers;

const parser = new parsers.Readline({ delimiter: '\r\n' });
const port = new SerialPort('/dev/cu.usbmodem2867281');

const files = {
	top: 'cool',
	left: 'metal',
	right: 'pop',
	bottom: 'techno',
	topleft: 'reggae',
	topright: 'world',
	topbottom: 'newWave',
	leftright: 'nantais',
};

let audio;

port.pipe(parser);
port.on('open', () => console.log('Port open'));
parser.on('data', data => {
	const result = data.split('#').filter(e => e !== '');
	console.log(result);
	switch (result.length) {
		case 1:
			if (audio) audio.kill();
			audio = player.play(`${__dirname}/sounds/${files[result[0]]}.wav`);
			break;
		case 2:
			if (audio) audio.kill();
			const name = result[0] + result[1];
			audio = player.play(`${__dirname}/sounds/${files[name]}.wav`);
			break;
			break;
		default:
			break;
	}
});
