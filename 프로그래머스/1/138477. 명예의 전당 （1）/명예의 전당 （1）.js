function solution(k, score) {
    var answer = [];
    var prize = [];
    for(var i=0;i<score.length;i++){
        if(prize.length < k) prize.push(score[i]);
        else {
            prize.sort((a,b) => b-a);
            var cur_min = prize[k-1];
            if (score[i] > cur_min){
                prize.pop();
                prize.push(score[i]);
            }
        }
        answer.push(Math.min(...prize));
    }
    return answer;
}