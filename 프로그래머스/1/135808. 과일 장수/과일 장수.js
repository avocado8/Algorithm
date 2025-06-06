function solution(k, m, score) {
    var answer = 0;
    score.sort((a,b) => b-a);
    for(var i=0;i+m <= score.length;i+=m){
        answer += score[i + m - 1] * m;
    }
    return answer;
}