namespace Task7 
{
    /*
    a)
        Definition algorithm (from skript):
        Ein Algorithmus ist eine eindeutige, endliche Beschreibung eines
        allgemeinen, endlichen Verfahrens zur schrittweisen Ermittlung
        gesuchter Größen aus gegebenen Größen
    
        eindeutige beschreibung:		ja
        endliche beschreibung:		    ja
        allgemeines verfahren:		    ?
        endliches verfahren:			ja
        schrittweise ermittlung:		ja
        gegebene größen:				ja

        gesamt daher:				    ja

    b)
        see "Task-7-b-ggT.png" in folder

    c)
        Pseudocode:

        read a
        read b
        m = a
        n = b
        r = 0
        while (r != 0) do
            if (m < n)
                then
                    temp = m
                    m = n
                    n = temp
            end-if
            r = m - n
            m = n
            n = r
        end-while
        write m
    */

    //d)
    int GreatestCommonDivisor(int a, int b)
    {
        int m = a;
        int n = b;
        //the -1 was just chosen because that should never be its value anyways, so its good for debugging
        int r = -1;
        while(r!=0)
        {
            if(m < n)
            {
                int temp = m;
                m = n;
                n = temp;
            }
            r = m - n;
            m = n;
            n = r;
        }
        return m;
    }
}