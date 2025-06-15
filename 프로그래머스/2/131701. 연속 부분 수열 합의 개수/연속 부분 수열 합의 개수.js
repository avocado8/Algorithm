function cntSum(arr, n){
    // n: 부분수열의 길이
    // 길이가 n인 부분수열로부터 나올 수 있는 합
    let res = [];
    for(let i=0;i<arr.length;i++){
        res.push(arr.slice(i%arr.length, (i+n)%arr.length));
    }
    let sums = new Set();
    for(let i of res){
        sums.add(i.reduce((acc, cur)=>acc+cur, 0));
    }
    sums.delete(0);
    return sums;
}

function solution(elements) {
    var answer = 0;
    var new_elements = elements.concat(elements);
    let res =[];
    for(let i=1;i<=elements.length;i++){
        // i : 부분수열길이
        let length_i_sums = cntSum(new_elements, i);
        res.push(length_i_sums);
    }
    return (new Set(res.flatMap(set => [...set])).size);
}