function isSatistifed(num1, num2){
    return num1<num2 && ([...num1.toString(2)].filter((el)=>el==="1").length ===
        [...num2.toString(2)].filter((el)=>el==="1").length);
}

function solution(n) {
    let next = n+1;
    while(1){
        if(isSatistifed(n, next)) break;
        else next++;
    }
    return next;
}