# cdb | Chronicles DB

Column-based in-memory time series database. Built in C++ from scratch.

# TO-DO

- persist the data using shared memory
- add generic table types -> generic data types
- add networking to receive commands
- SIMD instructions
- benchmark performance against other DBs

# DONE

# STRETCH GOALS

- add complex multithreaded capabilities (TBD)
- add in query language
- compression -> serialisation/deserialisation of data for performance?

# PLANNING (do not read)

Databases will process commands. They will also contain the tables and manage 
them. Tables will contain the data. For now, I will keep it simple. As I develop
this application later, there will be need for refactoring - but at the moment
there are incredibly complex components. That being said, I don't want to do
too much in the Database object for now, since it will probably be bloated with
many functionalities in the future.

This will likely need to be incorporated with a database engine. So later on the
DB will be a glorified parser:
It will contain: networking object which will return the commands, a parser object
which will parse the data then send the instructions off to the engine which
will send it off to the tables, which will do the queries?

Difficulties:
- Variant data types: store void*? Then we can't do optimizations later on with simd?
- std::string on my machine is 32 bytes, don't really want to std::variant with 4 byte ints
- decided to flyweight pattern: string intern all strings into an integer.