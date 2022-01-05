string encode(string src)
{
  //Your code here
  if (src.empty())
    return "";

  int i = 1;
  for (; i < src.length() && src[i] == src[i - 1]; i++);


  string temp = encode(src.substr(i));
  return src[0] + to_string(i) + temp;
}