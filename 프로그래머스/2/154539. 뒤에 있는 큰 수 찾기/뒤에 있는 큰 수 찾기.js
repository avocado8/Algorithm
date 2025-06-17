function solution(numbers) {
    var answer = Array(numbers.length).fill(-1);
    const stack = []; //인덱스 저장
    
    for(let i=0;i<numbers.length;i++){
        while(stack.length && numbers[stack[stack.length-1]] < numbers[i]){
            let idx = stack.pop();
            answer[idx]=numbers[i];
        }
        stack.push(i);
    }
    
    return answer;
}