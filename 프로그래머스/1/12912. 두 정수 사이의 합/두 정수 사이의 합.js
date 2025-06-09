function solution(a, b) {
    var answer = 0;
    var m = Math.max(a,b);
    var l = Math.min(a,b);
    for(let i=l;i<=m;i++){
        answer += i;
    }
    return answer;
}