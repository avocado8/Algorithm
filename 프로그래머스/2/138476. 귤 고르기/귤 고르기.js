function solution(k, tangerine) {
    const count = [0];
    for(let tan of tangerine){
        count[tan] = (count[tan] || 0) + 1;
    }
    count.sort((a,b)=>b-a);
    let tmp = 0
    let answer = 0;
    for(let i in count){
        // 개수 많은것부터 정렬되어있음
        // 많은 것부터 최대한 다 더하기
        if (tmp+count[i] >= k){
            answer++;
            break;
        }
        // 많은거 다 더해도 k보다 적으면 다 더하기
        tmp += count[i];
        answer++;
    }
    
    return answer;
}