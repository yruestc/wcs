#include "makeDictEn.h"
#include "makeDictCh.h"

/*
 * 词库形式: 单词 词频
 */
int main()
{
  std::string en_input_file = "../data/en_in.txt";
  std::string en_exclude_file = "../data/en_exclude.txt";
  std::string en_write_file = "../data/en_out.txt";
  const char* const DICT_PATH = "jieba.dict.utf8";
  const char* const HMM_PATH = "hmm_model.utf8";
  std::string ch_input_file = "../data/ch_in.txt";
  std::string ch_exclude_file = "../data/ch_exclude.txt";
  std::string ch_write_file = "../data/ch_out.txt";


  // 建立英文词库
  MakeDictEn dic;
  dic.readFile(en_input_file, en_exclude_file);
  dic.writeFile(en_write_file);

  // 建立中文词库
  MakeDictCh md(DICT_PATH, HMM_PATH);
  md.readFile(ch_input_file, ch_exclude_file);
  md.writeFile(ch_write_file);

  return 0;
}
