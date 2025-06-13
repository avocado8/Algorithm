function cntRemoving(s) {
    let result = 0;
    for(let i=0;i<s.length;i++){
        if(s[i] === "0") result++;
    }
    return result;
}
function binaryConvert(s) {
    return [...s].filter((el)=>el==="1").length.toString(2)
}

function solution(s) {
    let cnt = 0;
    let zeros = 0;
    while(s !== "1"){
        zeros += cntRemoving(s);
        s = binaryConvert(s);
        cnt++;
    }
    return [cnt, zeros]
}