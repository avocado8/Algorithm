function solution(prices) {
    var answer = Array(prices.length).fill(0);
    let stack = []; // 인덱스 저장
    for(let i=0;i<prices.length;i++){
        while(stack.length && prices[i] < prices[stack[stack.length-1]]){
            // 현재가가 더 작으면: 가격이 떨어진 것
            let top = stack.pop();
            answer[top] = i - top; // 현재인덱스 - 떨어진 가격 인덱스
        }
        stack.push(i);
    }
    
    while(stack.length){
        // 반복 끝난 후에 스택에 남아있는것: 가격이 떨어지지 않은 인덱스들
        // ex) 1이 남아있다면, 1번째 가격은 끝까지 가격이 안 떨어졌으므로 -> prices길이 - 인덱스 -1 (초니까) 만큼 버틴것임
        let top = stack.pop();
        answer[top] = prices.length - top - 1;
    }
    
    return answer;
}