/******************************************************************
*
* uHTTP for C++
*
* Copyright (C) Satoshi Konno 2002-2013
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/


#ifndef _CIO_INPUTSTREAM_H_
#define _CIO_INPUTSTREAM_H_

#include <string>
#include <uhttp/UHttpDef.h>

namespace uHTTP {
class InputStream {
 public:
  InputStream() {
  }

  virtual ~InputStream() {
  }

  virtual ssize_t read(std::string &b, size_t len) = 0;
  virtual ssize_t read(char *b, size_t len) = 0;

  ssize_t read(unsigned char *b, size_t len) {
    return read((char *)b, len);
  }

  virtual void unread(std::string &b, size_t off, size_t len) = 0;

  void unread(std::string &b, size_t len) {
     unread(b, 0, len);  
  }

  void unread(std::string &b) {
     unread(b, 0, (int)b.size());  
  }

  void unread(char c) {
    std::string b;
    b.append(&c, 0, 1);
    unread(b, 0, 1);  
  }

  virtual long skip(long n) = 0;

  virtual void close() = 0;
};

}

#endif
