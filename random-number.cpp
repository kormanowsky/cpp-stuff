int random_number(int min, int max){
  return (rand() % (max - min + 1)) + min;
}
