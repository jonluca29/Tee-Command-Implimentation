# Tee-Command-Implimentation
A minimal tee implementation in C that reads from stdin and writes to both stdout and a specified file. Supports -a to append instead of overwrite, and -i to ignore SIGINT.


## Usage

```bash
./myTee [flags] <file>
```

## Flags

| Flag | Description |
|------|-------------|
| `-a` | Append to the file instead of overwriting it |
| `-i` | Ignore SIGINT (Ctrl+C) |

## Examples

Write stdin to a file (overwrites if it exists):
```bash
echo "hello" | ./myTee output.txt
```

Append stdin to a file:
```bash
echo "world" | ./myTee -a output.txt
```

Ignore Ctrl+C while writing:
```bash
./myTee -i output.txt
```

Combine flags:
```bash
./myTee -a -i output.txt
```

## Building

```bash
gcc -o myTee myTee.c
```

## Notes

- Reads from stdin one character at a time
- Writes each character to both stdout and the specified file
- If the file cannot be opened, an error is printed and the program exits
- To stop input, send EOF with `Ctrl+D`
- If `-i` is set, use `kill -9 <pid>` to terminate the process
