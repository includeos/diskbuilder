#include "filetree.hpp"

#include <cstdio>
#include <cassert>
#include <libgen.h>
#include <sys/stat.h>

File::File(const char* path)
{
  const char* name = basename((char*) path);
  this->name = std::string(name);
  
  FILE* f = fopen(path, "rb");
  assert(f);
  
  fseek(f, 0, SEEK_END);
  this->size = ftell(f);
  rewind(f);

  this->data = std::unique_ptr<char[]> (new char[size], std::default_delete<char[]> ());
  fread(this->data.get(), this->size, 1, f);
  fclose(f);
}
Dir::Dir(const char* path)
{
  const char* name = basename((char*) path);
  this->name = std::string(name);
  
  /// ... ///
}

void FileSys::add(const char* path)
{
  struct stat s;
  if (stat(path, &s) == 0)
  {
    if (s.st_mode & S_IFDIR)
    {
      //dirs.emplace(path);
      return;
    }
    else {
      //files.emplace_back(path);
      return;
    }
  }
  assert(0);
}


void Dir::print(int level) const
{
  for (const Dir& d : subs)
  {
    printf ("Dir%*s ", level * 2, "");
    printf("[%u entries] %s\n",
          d.sectors_used(),
          d.name.c_str());
    
    d.print(level + 1);
  }
  for (const File& f : files)
  {
    printf("File%*s ", level * 2, "");
    printf("[%08u b -> %06u sect] %s\n",
          f.size,
          f.sectors_used(),
          f.name.c_str());
  }
}
void FileSys::print() const
{
  root.print(0);
}

uint32_t Dir::sectors_used() const
{
  uint32_t cnt = 0;
  for (const auto& dir : subs)
      cnt += dir.sectors_used();
  
  for (const auto& file : files)
      cnt += file.sectors_used();
  
  return cnt;
}