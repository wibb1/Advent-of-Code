const buildStartArray = () => {
	const line = new Array(1000).fill(0);
	return new Array(1000).fill(line);
};

const lightArray = buildStartArray();

const turnOnOrOffRow = (row, minIndex, maxIndex, value) => {
    for (let i = minIndex; i < maxIndex; i++) {
        row[i] = value
    }
};

const toggleRow = (row, minIndex, maxIndex) => {
    for (let i = minIndex; i < maxIndex; i++) {
        row[i] = row[i] === 1 ? 0 : 1;
    }
}

if (action === "turn on") {
    turnOnOrOffRow(row, minIndex, maxIndex, 1)
} else if (action === "turn off") {
        turnOnOrOffRow(row, minIndex, maxIndex, 0)
} else if (action === "toggle") {
    toggleRow(row, minIndex, maxIndex)
}