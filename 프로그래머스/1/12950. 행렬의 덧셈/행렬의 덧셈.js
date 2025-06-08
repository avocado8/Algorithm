function solution(arr1, arr2) {
    var answer = [];
    for(let i=0;i<arr1.length;i++){
        let tmp = Array.from(arr1[i], (el, idx) => el + arr2[i][idx])
        answer.push(tmp);
    }
    return answer;
}