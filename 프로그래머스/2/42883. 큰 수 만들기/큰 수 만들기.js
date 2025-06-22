function solution(number, k) {
    var answer = '';
    const stack = [];
    for(let n of number){
        while(k>0 && stack.length && stack[stack.length-1] < n){
            // 스택top에 있는 수가 현재수보다 작으면
            // 스택top에 있는 수는 지워야 하는 수임.
            stack.pop();
            k--;
        }
        stack.push(n);
    }
    if(k>0) stack.splice(stack.length -k, k);
    return stack.join('');
}