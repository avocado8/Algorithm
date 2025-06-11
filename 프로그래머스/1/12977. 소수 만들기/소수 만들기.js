function getPrime(n){
    let arr = Array(n+1).fill(true);
    arr[0] = arr[1] = false;
    for(let i=2;i*i<=n;i++){
        if(arr[i]){
            for(let j=i*i;j<=n;j+=i){
                arr[j] = false;
            }
        }
    }
    return arr;
}

function solution(nums) {
    let sum = nums.reduce((acc, cur)=>acc+cur, 0)
    let primes = getPrime(sum)
    let size = nums.length;
    let answer = 0;
    for(let i=0;i<size;i++){
        for(let j=i+1;j<size;j++){
            for(let k=j+1;k<size;k++){
                let tmp_sum = nums[i]+nums[j]+nums[k];
                if(primes[tmp_sum]) answer++;
            }
        }
    }
    return answer;
}