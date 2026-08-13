var frequencySort = function(s) {
    let mp = new Map();

    
    for (let char of s) {
        mp.set(char, (mp.get(char) || 0) + 1);
    }

    
    let arr = [...mp];

    
    arr.sort((a, b) => b[1] - a[1]);

    let str = "";

  
    for (let [char, freq] of arr) {
        str += char.repeat(freq);
    }

    return str;
};