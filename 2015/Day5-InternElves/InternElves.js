// Part 1

const checkNiceString = (string) => {
	let array = string.split("");
	let doubleArray = string.match(/.{1,2}/g);
	let string2 = string.slice(1);
	let doubleArray2 = string2.match(/.{1,2}/g);

	if (
		doubleArray.includes("ab") ||
		doubleArray.includes("cd") ||
		doubleArray.includes("pq") ||
		doubleArray.includes("xy") ||
		doubleArray2.includes("ab") ||
		doubleArray2.includes("cd") ||
		doubleArray2.includes("pq") ||
		doubleArray2.includes("xy")
	) {
		return false;
	}

	let threeVowels = false;
	let pair = false;
	let count = 0;
	let vowels = 0;

	while ((!threeVowels || !pair) && count < array.length) {
		if (!pair && array[count] === array[count + 1]) {
			pair = true;
		}
		if (!threeVowels && ["a", "e", "i", "o", "u"].includes(array[count])) {
			vowels++;
			if (vowels >= 3) threeVowels = true;
		}
		count++;
	}

	return pair && threeVowels;
};

function main0() {
	let nice = 0;
	input.forEach((string) => {
		if (checkNiceString(string)) nice++;
	});

	console.log(
		"There should be 236 and there are " +
			nice +
			" strings. \n" +
			"---------------------------------------------------\n"
	); // 236
}
// Part 2 -- not working!!! ********************************************************************************************
function main1() {
	const test1 = "qjhvhtzxzqqjkmpb"; //nice
	const test2 = "uurcxstgmygtbstg"; //naughty - has a pair (tg) but no repeat with a single letter between them
	const test3 = "ieodomkazucvgmuy"; //naughty - has a repeating letter with one between (odo), but no pair that appears twice

	testValue(test1);
	testValue(test2);
	testValue(test3);
	totalCount = 0;
	validStringArray.forEach((element) => {
		if (testValue(element)) totalCount++;
	});
	console.log(totalCount);
}

function testValue(str) {
	let success = pairWithOneBetween(str);
	if (success) {
		success = pairWithNoOverlap(str);
	}
	return success;
}

function pairWithNoOverlap(str) {
	const object = {};
	populateObject(str, object);
	const keys = Object.keys(object);
	let i = 0;
	while (i < keys.length) {
		let value = object[keys[i]];
		if (value.length > 1) {
			if (value.length > 2) return true;
			else if (value[0] + 1 != value[1]) return true;
		}
		i++;
	}
	return false;
}

function populateObject(str, object) {
	for (let i = 0; i < str.length; i++) {
		string = str.slice(i, i + 2);
		if (object[string]) object[string].push(i);
		else object[string] = [i];
	}
}

function pairWithOneBetween(str) {
	let success = false;
	let i = 0;
	while (i < str.length && success == false) {
		if (str.charAt(i) == str.charAt(i + 2)) {
			success = true;
		}
		i++;
	}
	return success;
}

main0()
main1();
