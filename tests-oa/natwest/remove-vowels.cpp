string removeVowels(string& s){
  vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
  for (int i=0; i<s.length(); i++){
    if (find(vowels.begin(),vowels.end(),s[i]) != vowels.end(){
      s = s.replace(i,1,"");
      i = i-1;
    }
  }
  return s;
}
