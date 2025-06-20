function solution(order) {
    var answer = 0;
    let cont_ptr = 1; // 컨테이너벨트
    let stack = []; // 보조컨테이너
    
    let cur_order_idx = 0; // 담아야 하는 상자 (인덱스)
    
    while(cur_order_idx < order.length){
        let target = order[cur_order_idx]; // 담아야 하는 상자
        
        let stack_top = stack[stack.length-1]; // 보조컨테이너 top
        if(stack.length && stack_top === target){
            // 보조 컨테이너에서 꺼낼 수 있는 경우
            stack.pop();
            answer++;
            cur_order_idx++;
        }
        else if(cont_ptr <= order.length){
            if(cont_ptr === target){
                // 컨테이너벨트에서 꺼낼 수 있는 경우
                answer++;
                cur_order_idx++;
            }
            else {
                // 보조 컨테이너로 옮기기
                stack.push(cont_ptr);
            }
            cont_ptr++;
        }
        else {
            break;
        }

    }
    
    
    return answer;
}