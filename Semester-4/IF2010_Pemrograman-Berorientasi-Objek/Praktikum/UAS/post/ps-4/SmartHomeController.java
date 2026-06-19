import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.Comparator;

public class SmartHomeController {
    private SmartHomeController() {}

    public static void printStatus(Object device) {
        Class<?> c = device.getClass();
        Field[] fields = c.getDeclaredFields();

        for (Field f : fields) {
            try {
                f.setAccessible(true); // Membuka akses untuk atribut private
                System.out.println(f.getName() + " = " + f.get(device));
            } catch (IllegalAccessException e) {
                System.out.println("FIELD_ACCESS_ERROR");
            }
        }
    }

    public static void printCommands(Object device) {
        Class<?> c = device.getClass();
        Method[] methods = c.getDeclaredMethods();

        Arrays.sort(methods, Comparator.comparing(Method::getName));

        for (Method m : methods) {
            System.out.println(m.getName());
        }
    }

    public static void execute(Object device, String command) {
        Class<?> c = device.getClass();
        try {
            Method method = c.getDeclaredMethod(command);
            method.setAccessible(true);
            method.invoke(device);
        } catch (NoSuchMethodException e) {
            System.out.println("COMMAND_NOT_FOUND");
        } catch (Exception e) {
            System.out.println("COMMAND_EXECUTION_ERROR");
        }
    }
}

