function solution(n) {
    var answer = 0;
    var tmp = n.toString(3);
    var tmp2 = "";
    for(var i=tmp.length-1;i>=0;i--){
        tmp2 += tmp[i];
    }
    console.log(tmp, tmp2)
    answer = parseInt(tmp2, 3)
    return answer;
}