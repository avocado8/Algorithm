function countNum(n){
    let nums = Array(10).fill(0);
    let str_n = n.toString();
    for(var i=0;i<n.length;i++){
        nums[Number(n[i])]++;
    }
    return nums;
}

function solution(X, Y) {
    var answer = '';
    let X_nums = countNum(X);
    let Y_nums = countNum(Y);
    // console.log(X_nums, Y_nums)
    
    let common = Array(10).fill(0);
    for(let i=0;i<10;i++){
        if(X_nums[i] <= Y_nums[i]) common[i] = X_nums[i];
        else common[i] = Y_nums[i];
    }
    // console.log(common)
    
    for(let i=9;i>=0;i--){
        if(common[i] > 0){
            answer = answer + i.toString().repeat(common[i]);
        }
    }
    if(answer.length===0) return "-1";
    if(answer[0] === "0" && answer.length > 1) return "0";
    return answer;
}