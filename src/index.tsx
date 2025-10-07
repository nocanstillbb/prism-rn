import PrismRn from './NativePrismRn';
import { useEffect, useState } from 'react';

export default PrismRn;

export function binding<T>(
    item: { [key: string]: any; register: (key: string, cb: (v: T) => void) => string; unregister: (id: any) => string },
    key: string
): [T, Function] {
    const [value, setValue] = useState(item[key]);

    useEffect(() => {
        const id = item.register(key, setValue);
        return () => {
            item.unregister(id);
        }
    }, []);

    return [value, setValue];
}