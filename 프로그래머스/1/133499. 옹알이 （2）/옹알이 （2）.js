function customSlice(str){
    var arr = [];
    var idx = 0;
    while(idx < str.length){
        if(str[idx]==="a" ||str[idx]==="w"){
            var tmp_str = str.slice(idx, idx+3);
            arr.push(tmp_str);
            idx += 3;
        }
        else if(str[idx]==="y" ||str[idx]==="m"){
            var tmp_str = str.slice(idx, idx+2);
            arr.push(tmp_str);
            idx += 2;
        }
        else {
            return [];
        }
    }
    return arr;
}

function solution(babbling) {
    const pos = [ "aya", "ye", "woo", "ma" ]
    var answer = 0;
    for(var i=0;i<babbling.length;i++){
        var arr = customSlice(babbling[i]);
        
        if(arr.length!=0 && arr.every(w => pos.includes(w))) {
            let isValid = true;
            for(var j=0;j<arr.length-1;j++){
                if(arr[j]===arr[j+1]){
                    isValid=false;
                    break;
                }
            }
            if(isValid) answer++;
        }
    }
    return answer;
}