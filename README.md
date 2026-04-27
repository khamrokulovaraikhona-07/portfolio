#  My Learning Journey — System Analysis, QA & Development
## 📂 Projects Overview
This repository showcases my **progressive growth in software engineering and testing**, starting from **modular C development** during an intensive month-long program, advancing through **web and mobile QA**, and extending into **database management and SQL querying**.  

---

### 1. T09D15 — Modular C Development & Build Automation

**What I Did:**
- Developed multi-module C projects: `data_module` and `yet_another_decision_module`.
- Implemented a **main executable module** with a structured Makefile (`all`, `clean`, `rebuild`).
- Created **parameterized macros** in `data_io_macro.h` for flexible array I/O.
- Built a **static library** (`data_stat.a`) and a **dynamic library** (`data_process.so`) and linked them.
- Ensured modular reuse of existing code using **preprocessor directives**.
- Organized a clean project structure with `src`, `data_libs`, and `build` folders.

**What I Learned:**
- Refactoring and debugging **multi-module projects** effectively.
- Designing and managing **Makefiles** with multiple build targets.
- Differences between **static vs dynamic linking** and appropriate use cases.
- Using **preprocessor directives and macros** for reusable, flexible code.
- Best practices for **modular programming**, project scalability, and maintainable code.

---

### 2. T15D24–T16D25 — Database Management System (DBMS)

**What I Did:**
- Developed a **custom DBMS in pure C** without external libraries.
- Created separate modules:  
  - `shared.c` for **universal operations** (`SELECT`, `INSERT`, `UPDATE`, `DELETE`).  
  - `[db_name].c` for **table-specific logic**.  
  - `modules_db.c` as **entry point** with control menu.
- Designed **aggregation queries** and ensured proper **data flow** between modules.
- Implemented **binary indexing** to optimize queries.
- Automated compilation through a Makefile with a `build_db` target.
- Conducted debugging and validation for accurate CRUD operations.

**What I Learned:**
- Building a **multi-table DBMS architecture** from scratch in C.
- Applying **binary indexing** for performance optimization.
- Managing **complex module interactions** in a large-scale project.
- Structuring programs with **shared libraries** and maintainable logic.
- Deepening understanding of **low-level data management**, **structs**, and memory organization.

---

### 3. QA2 — Web Test Artifacts

**What I Did:**
- Created **positive and negative test cases** for [saucedemo.com](https://www.saucedemo.com).  
- Documented **steps, preconditions, and expected results**.  
- Developed **checklists** and performed exploratory testing.  
- Filed **bug reports** with severity, priority, and evidence (screenshots/videos).

**What I Learned:**
- Structuring **test cases** for reproducibility.  
- Writing **effective bug reports**.  
- Using **checklists and exploratory testing** for coverage.  
- Distinguishing **functional vs non-functional testing**.

---

### 4. QA3 — Test Design & Analysis

**What I Did:**
- Applied **Boundary Value Analysis (BVA)** for a credit calculator.
- Built **State Transition Diagrams** for applicant.21 login.  
- Used **Pairwise Testing** to optimize test coverage.  
- Applied **Equivalence Partitioning** and **State Transition Testing**.

**What I Learned:**
- Reducing **test coverage** without losing quality.  
- **Visual modeling** of system behavior.  
- Efficient identification of **critical edge cases**.

---

### 5. QA6 — Web Testing

**What I Did:**
- Studied **3-tier and multi-tier client-server architectures**.  
- Analyzed system **fault tolerance** with hot and cold backups.  
- Investigated **cookies** (Secure, HttpOnly, SameSite) using DevTools.  
- Performed **UI/UX testing** comparing Figma mockups with websites.  
- Filed bug reports for **visual and functional inconsistencies**.

**What I Learned:**
- Evaluating **cross-browser compatibility**.  
- Monitoring **network requests** and protocols (HTTP/HTTPS).  
- Understanding the role of **cookies** in UX and security.

---

### 6. QA8 — Mobile Testing

**What I Did:**
- Tested for **external interruptions, app modes, and memory leaks**.  
- Explored **native, hybrid, web, and cross-platform apps**.  
- Analyzed **Android and iOS architectures**.  
- Worked with **emulators and simulators**.  
- Captured logs and used **Charles Proxy** for network analysis.

**What I Learned:**
- Practical testing of **mobile apps** on multiple platforms.  
- Simulating **real-world conditions**.  
- Using **logging and network monitoring** for debugging and performance checks.

---

### 7. SQL Bootcamp

**What I Did:**
- Worked with relational tables: `pizzeria`, `person`, `menu`, `person_visits`, `person_order`.  
- Wrote **ANSI SQL queries** for selection, filtering, sorting, and calculations.  
- Created queries for specific conditions (e.g., residents of Kazan, visitors on certain dates).  
- Applied constructs: `BETWEEN`, `ORDER BY`, `DISTINCT`, `CASE WHEN`, nested queries.

**What I Learned:**
- Analyzing **relational data** and table relationships.  
- Writing **efficient SQL queries**.  
- Using **calculated fields** and conditional logic.  
- Managing **complex selection criteria** without joins (when restricted).

---

##  Tech Stack

- **Languages & Tools:** C, SQL, Markdown  
- **Build & Debug:** GCC, Makefile, Valgrind  
- **Database Systems:** PostgreSQL, MySQL  
- **Testing Tools:** Charles Proxy, Android Studio, Xcode, Chrome DevTools  
- **Documentation:** Notion, Jira, Figma, Markdown  
- **Version Control:** Git / GitHub  

---

## Summary

This repository reflects my **structured approach to learning and development**, combining **software design, testing, and data analysis**, and highlights my ability to **adapt to different tools and methodologies** across projects.