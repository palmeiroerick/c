use std::io::{self, Write}; 

fn r_putnbr(mut num: i32) -> io::Result<()> {
    let mut buffer: [u8; 11] = [0; 11];
    let mut size: usize = 0;
    let mut divisor: i32 = 1;

    if num < 0 {
        buffer[size] = b'-';
        size += 1;
    }

    if num > 0 { num = -num; }
 
    while num / divisor <= -10 { divisor *= 10; }

    while divisor > 0 {
        buffer[size] = (b'0' as i32 - (num / divisor % 10)) as u8;
        divisor /= 10;
        size += 1;
    }

    io::stdout().write_all(&buffer[..size])?;

    Ok(())
}

fn main() {
    let _ = r_putnbr(0x7fffffffu32 as i32);
    println!();
    let _ = r_putnbr(0x80000000u32 as i32);
    println!();
    let _ = r_putnbr(0xffffffffu32 as i32);
    println!();
    let _ = r_putnbr(0x00000000u32 as i32);
    println!();
    let _ = r_putnbr(0x00000045u32 as i32);
    println!();
}