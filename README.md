# 🔍 Inverted Search using Hashing

## 📌 Project Overview
**Inverted Search** is a document indexing system that maps words (or terms) to the locations in which they appear across multiple files. This project implements an **inverted index** using **hashing** and **singly linked lists** in C, providing a lightweight full-text search engine for a given set of documents.

This is a core concept used in **search engines**, enabling fast retrieval of documents based on keyword queries. Instead of scanning the entire content every time, the index helps directly locate the files containing the searched terms.

---

## 🚀 Features
- Accepts multiple `.txt` files to create the database
- Generates an inverted index using hashing
- Maps each word to:
  - File(s) where it appears
  - Number of occurrences in each file
- Supports:
  - Displaying the complete database
  - Searching for a specific word
  - Updating the database with new files
  - Saving/loading the index to/from a file

---

## 🧠 Pre-requisites
To understand and work with this project, you should be familiar with:
- Hashing techniques
- Singly linked lists
- File I/O operations in C

---

## 🛠️ Tech Stack
- **Language**: C
- **Data Structures**: Hash Table + Linked Lists
- **Storage**: Text files as input and output

---
