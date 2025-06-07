function solution(numbers) {
    var answer = [];
    let a = new Set();
    for(let i=0;i<numbers.length-1;i++){
        for(let j=i+1;j<numbers.length;j++){
            a.add(numbers[i]+numbers[j]);
        }
    }
    console.log(a);
    answer = Array.from(a).sort((a,b) => a-b);
    return answer;
}