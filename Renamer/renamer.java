import java.io.*;
import java.net.URI;
import java.util.ArrayList;

class filter implements FilenameFilter
{
	public boolean accept(File dir, String k)
	{
		return (k.endsWith(".m4a")||k.endsWith(".mp3")) && k.contains("-");
	}
}

public class renamer
{
	static File f;
	public static void main(String[] args)
	{
		f=new File(args[0]);

		String files[]=f.list(new filter());

		for(int i=0;i<files.length;i++)
		{	
			File f2=new File(f,files[i]);

			String m=renamingfun(f2.getName());
			System.out.print(m+" ");

			//This function replaces the original files with the new files.
			boolean res=f2.renameTo(new File("/home/saarang/Downloads/Renamer/"+m));
			System.out.println(res);
		}


		
	}

	public static String renamingfun(String k)
	{
		//Use the strings properly to custom fit the present requirement.

		int l=k.indexOf("- ");
		int r=k.indexOf("(");
		int lt=r-1;
		if(r==-1)
		{
			r=k.indexOf(".m");
			lt=r;
		}
		String s="";
		for(int i=l+2;i<lt;i++)
			s+=k.charAt(i);

		for(int i=0;i<4;i++)
		{
			s+=k.charAt(k.length()-4+i);
		}
		return s;
	}
}