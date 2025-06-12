function makeFinalStr(str){
    let result = "";
    for(let i=0;i<str.length;i++){
        if(str[i] === "1") result += "#"
        else if(str[i] === "0") result += " "
    }
    return result;
}
function solution(n, arr1, arr2) {
    var answer = [];
    for(let i=0;i<n;i++){
        let nor = (arr1[i] | arr2[i]);
        let nor_str = nor.toString(2);

        if(nor_str.length < n) nor_str = "0".repeat(n-nor_str.length) + nor_str;
        else nor_str = nor_str.slice(-n);
        console.log(nor_str); 
        
        answer.push(makeFinalStr(nor_str));
    }
    return answer;
}