function solution(arr1, arr2) {
    let a_row = arr1.length;
    let a_col = arr1[0].length;
    let b_row = arr2.length;
    let b_col = arr2[0].length;
    var answer = Array.from({length: a_row}, () => Array(b_col).fill(0));
    for(let r=0;r<a_row;r++){
        for(let c=0;c<b_col;c++){
            for(let k=0;k<a_col;k++){
                answer[r][c] += arr1[r][k] * arr2[k][c];
            }
        }
    }
    return answer;
}

// 3x2  2x2   3x2
// 1 4  3 3 = 3+12 3+12
// 3 2  3 3   9+6  9+6
// 4 1        12+3 12+3