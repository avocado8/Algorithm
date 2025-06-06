function getSub(num){
    // 약수 개수 구하기
    var answer = 0;
    for(var i=0;i*i<=num;i++){
        if (num % i == 0) {
            answer++;
            if (i != num / i){
                answer++;
            }
        }
    }
    return answer;
}

function solution(number, limit, power) {
    var answer = 0;
    for(var i=1; i<=number;i++){
        var subs = getSub(i);
        if (subs <= limit) answer += subs;
        else answer += power;
    }
    return answer;
}