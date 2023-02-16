const md5 = require('md5');

const checkHash = (hash, string) => {
    return hash.slice(0,string.length) === string
}

const findHash = (input, string) => {
    let hash = md5(input);
    if (checkHash(hash, string)) return ""
    let number = -1;

    do {
        number++;
        hash = md5(input + number);
    } while (!checkHash(hash, string)); 

    console.log("answer =", number)
}

const input = "bgvyzdsv";
findHash(input, "000000");