function solution(n) {
    let tmp = 0;
    let answer = 0;
    for(let i=1;i<=Math.ceil(n/2);i++){
        tmp = i;
        for(let j=i+1;j<=Math.ceil(n/2);j++){
            tmp += j;
            if(tmp > n) break;
            if(tmp === n){
                answer++;
                break;
            }
        }
    }
    return ++answer;
}